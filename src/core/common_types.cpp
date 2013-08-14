/* 
 * File:   common_types.cpp
 * Author: kirill
 * 
 * Created on July 29, 2013, 9:56 AM
 */

#include "common_types.h"

#include <assert.h>

std::map<charge_balance, std::string> cb_names::mp_cb;
cb_names::cb_init cb_names::_init;

c_man_atom_prop_item::c_man_atom_prop_item(const c_man_atom_prop_item & orig)
{
  if(orig.charge_specified)
  {
    charge = orig.charge;
    charge_specified = true;
  }

  if(orig.fixed_specified)
  {
    fixed = orig.fixed;
    fixed_specified = true;
  }

  if(orig.popul_specified)
  {
    manual_pop = orig.manual_pop;
    popul_specified = true;
  }
}

cb_names::cb_init::cb_init()
{
  cb_names::mp_cb[cb_no]     = "no";
  cb_names::mp_cb[cb_formal] = "form";
  cb_names::mp_cb[cb_input]  = "yes";
  cb_names::mp_cb[cb_try]    = "try";
}

std::string cb_names::get_name(const charge_balance cb)
{
  std::string result = mp_cb[cb];
  assert(result != "");
  return result;
}

bool cb_names::get_cb(const std::string str, charge_balance &cb)
{
  bool result = false;
  
  for(std::map<charge_balance, std::string>::const_iterator it  = mp_cb.begin(); 
                                                            it != mp_cb.end(); it++ )
  {
    result = result || (it->second == str);
    if(result) 
    {
      cb = it->first;
      break;
    }  
  }
  return result;  
}


//---------------

c_man_atom_prop::c_man_atom_prop()
{
  
}

void c_man_atom_prop::convert_properties(const std::set<std::string> &labels)
{
  assert(false);
}

c_man_atom_prop::~c_man_atom_prop()
{

}


