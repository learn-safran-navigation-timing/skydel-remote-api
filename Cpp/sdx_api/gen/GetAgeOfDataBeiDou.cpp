
#include "gen/GetAgeOfDataBeiDou.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAgeOfDataBeiDou
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAgeOfDataBeiDou::CmdName = "GetAgeOfDataBeiDou";
    const char* const GetAgeOfDataBeiDou::Documentation = "Get BeiDou Age of data, Ephemeris (AODE) and Age of data, Clock (AODC)";

    REGISTER_COMMAND_FACTORY(GetAgeOfDataBeiDou);


    GetAgeOfDataBeiDou::GetAgeOfDataBeiDou()
      : CommandBase(CmdName)
    {

    }

    GetAgeOfDataBeiDouPtr GetAgeOfDataBeiDou::create()
    {
      return std::make_shared<GetAgeOfDataBeiDou>();
    }

    GetAgeOfDataBeiDouPtr GetAgeOfDataBeiDou::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAgeOfDataBeiDou>(ptr);
    }

    bool GetAgeOfDataBeiDou::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetAgeOfDataBeiDou::documentation() const { return Documentation; }


    int GetAgeOfDataBeiDou::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
