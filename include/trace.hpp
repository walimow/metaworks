//
// Created by kh on 04.08.20.
//

#ifndef METAWORKS_TRACE_HPP
#define METAWORKS_TRACE_HPP

#include "defines.hpp"
#include <iostream>

namespace metaworks::kind::buildin {

  static void trace_type_info(const TI &tinfo, int index) {
      std::cout << tinfo.name() << " - (" << tinfo.hash_code() << ") " << index << std::endl;
  }

}


#endif //METAWORKS_TRACE_HPP
