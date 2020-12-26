//
// Created by kh on 23.12.20.
//

#ifndef METAWORKS_INFO_HPP
#define METAWORKS_INFO_HPP

#include "defines.hpp"
#include <eal/fo.hpp>
#include <kind.hpp>

#include <typeinfo>

namespace sfo = stepworks::eal::fo;

namespace metaworks::typeinfo {

    template<typename...>
    struct info;

    template<typename Ty>
    struct info<Ty> {
        static auto kind_t() { return metaworks::kind::atom; }

        auto type_name() {
            return typeid(Ty).name();
            //std::cout << tinfo.name() << " - (" << tinfo.hash_code() << ") " << index << std::endl;
        }
    };

    template<typename Ty, typename ...Args>
    struct info<typename sfo::ft<Ty, Args...> > {
        static auto kind_t() { return metaworks::kind::fform; }
    };


    template<template<typename...> typename M, typename ...Args>
    struct info<M<Args...> > {
        static auto kind_t() { return metaworks::kind::mform; }
    };


}


#endif //METAWORKS_INFO_HPP
