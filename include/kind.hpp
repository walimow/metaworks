//
// Created by karsten on 03.08.20.
//

#ifndef METAWORKS_KIND_HPP
#define METAWORKS_KIND_HPP

#include <utility>

#include <iostream>
#include <typeinfo>
#include "trace.hpp"
#include <map>
#include <string>

//using Ft_0 =void(bool);

using std::type_info;

using Ft_t = void(const std::type_info &, int);

namespace metaworks::kind {

    using ktype_t = enum kt {
        atom,
        form,     // any T=F<Args...>
        fform,    //    functional form withd ft/ff (fo), with or without bounded args
        mform,     //metaform
        seq        ///tuple like
    };

    static auto _ek_() {
        static std::map<ktype_t, std::string> ekind_types{{atom,  "atom"},
                                                          {form,  "form"},
                                                          {fform, "fform"},
                                                          {mform, "mform"},
                                                          {seq,   "seq"}};
        return ekind_types;
    }


    template<typename...>
    struct kind_t;

    template<typename Ta>
    struct kind_t<Ta> {
        const static std::size_t value = 1;

        static void ft0(Ft_t f, int x = 0) {
            f(typeid(Ta), x);
        }
    };


    template<typename Ta>
    auto get_kind_sz(const Ta &) {
        return kind_t<Ta>::value;
    }

    template<typename Ta>
    auto get_kind(const Ta &) {
        return kind_t<Ta>{};
    }

    template<typename Ta>
    void f_kind(const Ta &, Ft_t f) {
        kind_t<Ta>::ft0(f);
    }

    template<typename Ty, typename ...Rest>
    struct kind_t<Ty, Rest...> {
        const static std::size_t value = kind_t<Ty>::value + kind_t<Rest...>::value;

        static void ft0(Ft_t f, int x = 0) {
            f(typeid(Ty), x);
            kind_t<Rest...>::ft0(f, ++x);
        }
    };

    template<typename ...Args>
    auto get_kind_sz(const Args &...) {
        return kind_t<Args...>::value;
    }


    template<typename ...Args>
    auto get_kind(const Args &...) {
        return kind_t<Args...>{};
    }


    //   static constexpr  ktype get_ktype(){ return seq;}

    template<typename ...Args>
    void f_kind(const Args..., Ft_t f) {
        kind_t<Args...>::ft0(f);
    }


/// <summary>
/// @todo
/// </summary>
/// <typeparam name="...Args"></typeparam>
    template<template<typename...> typename F, typename ...Args>
    struct kind_t<F<Args...>> {
        const static std::size_t value = 1 + kind_t<Args...>::value;
        const static ktype_t ktype = form;

        static void ft0(Ft_t f, int x = 0) {
            f(typeid(F<Args...>), x);
            kind_t<Args...>::ft0(f /*,++x*/);
        }
    };

    // static  ktype get_ktype(){ return  form;}

    template<template<typename...> typename F, typename ...Args>
    auto get_kind_sz(const F<Args...> &) {
        return kind_t<F<Args...>>::value;
    }


    template<template<typename...> typename F, typename ...Args>
    auto get_kind(const F<Args...> &) {
        return kind_t<F<Args...>>{};
    }


    template<template<typename ...> typename Form, typename Ta>
    struct kind_t<Form<Ta>> {
        const static std::size_t value = 1 + kind_t<Ta>::value;
        const static ktype_t ktype = form;

        static void ft0(Ft_t f, int x = 0) {
            f(typeid(Form<Ta>), x++);
            kind_t<Ta>::ft0(f, x);
        }
    };

    template<template<typename ...> typename Form, typename Ta>
    auto get_kind_sz(const Form<Ta> &) {
        return kind_t<Form<Ta>>::value;
    }

    template<template<typename ...> typename SForm,
            template<typename ...> typename Form, typename Ta>
    struct kind_t<SForm<Form<Ta>>> {
        //const static  ktype_t ktype=mform;
        const static std::size_t value = 1 + kind_t<Form<Ta>>::value;

        static void ft0(Ft_t f, int x = 0) {
            f(typeid(SForm<Form<Ta>>), x++);
            kind_t<Form<Ta>>::ft0(f, x);
        }

    };


    template<template<typename ...> typename SForm,
            template<typename ...> typename Form, typename Ta>
    auto get_kind_sz(const SForm<Form<Ta>> &) {
        return kind_t<SForm<Form<Ta>>>::value;
    }

    template<template<typename ...> typename SForm,
            template<typename ...> typename Form, typename Ta>
    auto get_kind(const SForm<Form<Ta>> &) {
        return kind_t<SForm<Form<Ta>>>{};
    }

    template<template<typename ...> typename SForm,
            template<typename ...> typename Form, typename ...Ta>
    auto f_kind(const SForm<Form<Ta...>> &, Ft_t f) {
        return kind_t<SForm<Form<Ta...>>>::ft0(f);
    }

    template<typename Ta>
    constexpr auto ekind(const Ta &) {
        return atom;
    }

    template<typename ...Ta>
    constexpr auto ekind(const Ta &...) {
        return seq;
    }


    template<template<typename...> typename Form, typename ...As>
    constexpr auto ekind(const Form<As...> &) {
        return form;
    }

    template<template<typename...> typename SForm,
            template<typename...> typename Form,
            typename ...As>
    constexpr auto ekind(const SForm<Form<As...>> &) {
        return mform;
    }


    template<typename Ty>
    void apply_kind_f(const Ty & /*a*/, Ft_t f) {
        kind_t<Ty>::ft0(f);
    }

    template<typename Ty>
    void trace_kind_f(const Ty &a) {
        std::cout << _ek_()[ekind(a)] << "\n";
        kind_t<Ty>::ft0(metaworks::kind::buildin::trace_type_info);
    }


    template<template<typename...> typename F, typename Ty>
    void trace_kind_f(const F<Ty> &a) {
        std::cout << _ek_()[ekind(a)] << "\n";
        kind_t<F<Ty>>::ft0(metaworks::kind::buildin::trace_type_info);
    }
}


#endif //METAWORKS_KIND_HPP
