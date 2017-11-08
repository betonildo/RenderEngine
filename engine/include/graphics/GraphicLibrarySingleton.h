#ifndef GRAPHICLIBRARYSINGLETON_H
#define GRAPHICLIBRARYSINGLETON_H

#include "OSExport.h"
#include "graphics/GraphicLibrary.h"

class ENGINE_API GraphicLibrarySingleton {

public:
    template <class GraphicLibraryType>
    static void setInstance() {
        GraphicLibrarySingleton::setInstance(new GraphicLibraryType());
    }

    static GraphicLibrary* getInstance();
    
private:
    static void setInstance(GraphicLibrary* gl);
    
};

#endif /**/