#ifndef MATRIX_H
#define MATRIX_H

// Study more on macro preprocessors to make optimizations at compile time
// #include <CustomMacros.h>

// template<int numberOfRows, int numberOfColumns, class NumberType>
// class Matrix {

//     union {
//         NumberType m_1d[numberOfRows * numberOfColumns];
//         NumberType m_2d[numberOfRows][numberOfColumns];
//     };

// public:

//     // inline friend Matrix<numberOfRows, numberOfColumns, NumberType>&
//     // operator*   (const Matrix<numberOfRows, numberOfColumns, NumberType>& m1,
//     //             const Matrix<numberOfRows, numberOfColumns, NumberType>& m2) {
        
//     //     Matrix<numberOfRows, numberOfColumns, NumberType> m3;

//     //     REP(0, (numberOfRows * numberOfColumns) / 10, numberOfRows * numberOfColumns, 
//     //         {
//     //             m3.m_1d[__COUNTER__] = m1.m_1d[__COUNTER__ ] 
//     //         };
//     //     )
//     // }

// };

// using Matrix4x4 = Matrix<4,4,float>;

#endif /*MATRIX_H*/