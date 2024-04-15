
#include "GetGlonassDoubleParams.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassDoubleParams::CmdName = "GetGlonassDoubleParams";
    const char* const GetGlonassDoubleParams::Documentation = "Please note the command GetGlonassDoubleParams is deprecated since 21.3. You may use GetGlonassEphDoubleParamForEachSV.\n"
      "\n"
      "Get GLONASS parameter value for all satellites\n"
      "\n"
      "Name      Type   Description\n"
      "--------- ------ ---------------------------------------------------------\n"
      "ParamName string Refer to SetGlonassEphDoubleParamForSV for accepted names";
    const char* const GetGlonassDoubleParams::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGlonassDoubleParams);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGlonassDoubleParams);


    GetGlonassDoubleParams::GetGlonassDoubleParams()
      : CommandBase(CmdName, TargetId)
    {}

    GetGlonassDoubleParams::GetGlonassDoubleParams(const std::string& paramName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
    }

    GetGlonassDoubleParamsPtr GetGlonassDoubleParams::create(const std::string& paramName)
    {
      return std::make_shared<GetGlonassDoubleParams>(paramName);
    }

    GetGlonassDoubleParamsPtr GetGlonassDoubleParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassDoubleParams>(ptr);
    }

    bool GetGlonassDoubleParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
        ;

    }

    std::string GetGlonassDoubleParams::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGlonassDoubleParams::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName"}; 
      return names; 
    }


    int GetGlonassDoubleParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGlonassDoubleParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGlonassDoubleParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
