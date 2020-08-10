//
// Created by karsten on 08.08.20.
//

#ifndef METAWORKS_APPLY_HPP
#define METAWORKS_APPLY_HPP

namespace metaworks {

    /// the typed ptr in the function call is necessary for code specification, but the value itself should not be used,
    /// the ptr generally may considered as nullptr or linked to an invalid instance

    template<typename Ta, typename Tb, typename ...Context>
    auto apply(const Ta *ptr_dont_use, Tb (f)(const Ta *ptr, const Context &...), Context...context) {
        return f(ptr_dont_use, context...);
    }

    template<typename Ta, typename F, typename ...Context>
    auto apply(const Ta *ptr_dont_use, const F &f, Context...context) {
        return f(ptr_dont_use, context...);
    }


}

#endif //METAWORKS_APPLY_HPP
