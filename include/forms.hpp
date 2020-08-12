//
// Created by karsten on 12.08.20.
//

#ifndef METAWORKS_FORMS_HPP
#define METAWORKS_FORMS_HPP

#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <tuple>
#include <list>

namespace metaworks::kind {

    template <typename ...>  struct form_type;

    template <template <typename ...> typename any_form_t, typename ... types>
    struct  form_type <any_form_t<types... >>{
        static constexpr  const char* ft_name="aform";
    };

    template < typename ... types>
    struct  form_type <std::vector<types... >>{
        static constexpr  const char* ft_name="vector";
    };

    template < typename ... types>
    struct  form_type <std::set<types... >>{
        static constexpr  const char* ft_name="set";

    };

    template < typename ... types>
    struct  form_type <std::unordered_set<types... >>{
        static constexpr  const char* ft_name="unordered_set";

    };


    template < typename ... types>
    struct  form_type <std::map<types... >>{
        static constexpr  const char* ft_name="map";
    };


    template < typename ... types>
    struct  form_type <std::unordered_map<types... >>{
        static constexpr  const char* ft_name="unordered_map";
    };

    template < typename ... types>
    struct  form_type <std::list<types... >>{
        static constexpr  const char* ft_name="list";
    };

    template < std::size_t N, typename  T>
    struct  form_type <std::array<T, N >>{
        static constexpr  const char* ft_name="array";
        static constexpr const std::size_t  sz =N;
    };


    template < typename Ta, typename Tb>
    struct  form_type <std::pair<Ta,Tb >>{
        static constexpr  const char* ft_name="pair";
    };


    template < typename ...Types>
    struct  form_type <std::tuple<Types...>>{
        static constexpr  const char* ft_name="tuple";
    };
}

#endif //METAWORKS_FORMS_HPP
