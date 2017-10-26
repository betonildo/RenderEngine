#include <iostream>
#include <string.h>
class MyType {

public:
    float d1, d2, d3;
};

std::ostream& operator<<(std::ostream& os, const MyType& mt) {
    os << mt.d1 << " " << mt.d2 << " " << mt.d3;
    return os;
}

template <class GLApiImpl>
class GLApi {

};


class OpenGL {

};

typedef GLApi<OpenGL> GL;

int main( int argc, char **argv ) {

    MyType mt;
    float asd[] = {2.0, 3.0, 4.0};
    memcpy(&mt, asd, sizeof(MyType));

    std::cout << mt << std::endl;


    return 0;
}