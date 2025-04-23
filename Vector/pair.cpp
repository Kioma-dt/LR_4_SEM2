#include "pair.h"

template <typename T1, typename T2>
Pair<T1, T2> &Pair<T1, T2>::operator=(const Pair &other){
    if (this != &other){
        first = other.first;
        second = other.second;
    }

    return *this;
}

template <typename T1, typename T2>
Pair<T1, T2> &Pair<T1, T2>::operator=(Pair &&other){
    if (this != &other){
        first = std::move(other.first);
        second = std::move(other.second);
    }

    return *this;
}

// template <typename T1, typename T2>
// template <typename U1, typename U2>
// Pair<T1, T2> &Pair<T1, T2>::operator=(const Pair<U1, U2> &other){
//     if (this != &other){
//         first = other.first;
//         second = other.second;
//     }

//     return *this;
// }

// template <typename T1, typename T2>
// template <typename U1, typename U2>
// Pair<T1, T2> &Pair<T1, T2>::operator=(Pair<U1, U2> &&other){
//     if (this != &other){
//         first = std::move(other.first);
//         second = std::move(other.second);
//     }

//     return *this;
// }

template <typename T1, typename T2>
Pair<T1, T2> make_pair(T1 &&fir, T2&& sec){
    return Pair<T1, T2>(std::forward<T1>(fir), std::forward<T2>(sec));
}