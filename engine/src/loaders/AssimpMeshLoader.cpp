#include "loaders/AssimpMeshLoader.h"
#include "assets/Mesh.h"
/* assimp include files. These three are usually needed. */
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
// const struct aiScene* scene = NULL; 

// /* ---------------------------------------------------------------------------- */
// void get_bounding_box_for_node (const struct aiNode* nd,
// 	struct aiVector3D* min,
// 	struct aiVector3D* max,
// 	struct aiMatrix4x4* trafo
// ){
// 	struct aiMatrix4x4 prev;
// 	unsigned int n = 0, t;

// 	prev = *trafo;
// 	aiMultiplyMatrix4(trafo,&nd->mTransformation);

// 	for (; n < nd->mNumMeshes; ++n) {
// 		const struct aiMesh* mesh = scene->mMeshes[nd->mMeshes[n]];
// 		for (t = 0; t < mesh->mNumVertices; ++t) {

// 			struct aiVector3D tmp = mesh->mVertices[t];
// 			aiTransformVecByMatrix4(&tmp,trafo);

// 			min->x = aisgl_min(min->x,tmp.x);
// 			min->y = aisgl_min(min->y,tmp.y);
// 			min->z = aisgl_min(min->z,tmp.z);

// 			max->x = aisgl_max(max->x,tmp.x);
// 			max->y = aisgl_max(max->y,tmp.y);
// 			max->z = aisgl_max(max->z,tmp.z);
// 		}
// 	}

// 	for (n = 0; n < nd->mNumChildren; ++n) {
// 		get_bounding_box_for_node(nd->mChildren[n],min,max,trafo);
// 	}
// 	*trafo = prev;
// }

// /* ---------------------------------------------------------------------------- */
// void get_bounding_box (struct aiVector3D* min, struct aiVector3D* max)
// {
// 	struct aiMatrix4x4 trafo;
// 	aiIdentityMatrix4(&trafo);

// 	min->x = min->y = min->z =  1e10f;
// 	max->x = max->y = max->z = -1e10f;
// 	get_bounding_box_for_node(scene->mRootNode,min,max,&trafo);
// }

// /* ---------------------------------------------------------------------------- */
// int loadasset (const char* path)
// {
// 	/* we are taking one of the postprocessing presets to avoid
// 	   spelling out 20+ single postprocessing flags here. */
// 	scene = aiImportFile(path, aiProcessPreset_TargetRealtime_MaxQuality);

// 	if (scene) {
// 		get_bounding_box(&scene_min,&scene_max);
// 		scene_center.x = (scene_min.x + scene_max.x) / 2.0f;
// 		scene_center.y = (scene_min.y + scene_max.y) / 2.0f;
// 		scene_center.z = (scene_min.z + scene_max.z) / 2.0f;
// 		return 0;
// 	}
// 	return 1;
// }

Mesh AssimpMeshLoader::load(const char* path) {

    const struct aiScene* scene_local = aiImportFile(path, aiProcessPreset_TargetRealtime_MaxQuality);
    const struct aiNode* nd = scene_local->mRootNode->mChildren[0]; // ROOT CHILDREN ONLY
    
    Mesh m;

    std::vector<Vector3> vertices;
    std::vector<Vector3> normals;
    std::vector<Vector2> uvs;
    std::vector<unsigned int> indices;

	for (uint n = 0; n < nd->mNumMeshes; ++n) {
		const struct aiMesh* mesh = scene_local->mMeshes[nd->mMeshes[n]];
		for (uint t = 0; t < mesh->mNumVertices; ++t) {

			aiVector3D tmp = mesh->mVertices[t];
			// POPULATE VERTICES
            vertices.emplace_back(tmp.x, tmp.y, tmp.z);
		}

		for (uint t = 0; t < mesh->mNumFaces; ++t) {
			const struct aiFace* face = &mesh->mFaces[t];
			// GLenum face_mode;

			// switch(face->mNumIndices) {
			// 	case 1: face_mode = GL_POINTS; break;
			// 	case 2: face_mode = GL_LINES; break;
			// 	case 3: face_mode = GL_TRIANGLES; break;
			// 	default: face_mode = GL_POLYGON; break;
			// }

			for(uint i = 0; i < face->mNumIndices; i++) {
				int index = face->mIndices[i];
				//POPULATE INDICES
				indices.push_back(index);
				if(mesh->mNormals != NULL) {

					//POPULATE NORMALS
					aiVector3D normal = mesh->mNormals[index];
					normals.emplace_back(normal.x, normal.y, normal.z);
				}
			}

			if (mesh->HasTextureCoords(0)) {

				for (uint i = 0; i < mesh->mNumUVComponents[0]; i++) {
					aiVector3D uv = mesh->mTextureCoords[0][i];
					uvs.emplace_back(uv.x, uv.y);
				}
			}
		}
	}


    m.setPositions(vertices);
    m.setNormals(normals);
    m.setUV(uvs);
    m.setIndices(indices);

	aiReleaseImport(scene_local);

    return m;
}