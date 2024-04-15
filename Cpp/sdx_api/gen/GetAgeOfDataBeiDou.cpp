
#include "GetAgeOfDataBeiDou.h"

#include "command_factory.h"
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
    const char* const GetAgeOfDataBeiDou::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAgeOfDataBeiDou);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAgeOfDataBeiDou);


    GetAgeOfDataBeiDou::GetAgeOfDataBeiDou()
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetAgeOfDataBeiDou::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetAgeOfDataBeiDou::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
