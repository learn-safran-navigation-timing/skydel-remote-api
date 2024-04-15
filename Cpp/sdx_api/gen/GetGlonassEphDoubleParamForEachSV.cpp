
#include "GetGlonassEphDoubleParamForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassEphDoubleParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassEphDoubleParamForEachSV::CmdName = "GetGlonassEphDoubleParamForEachSV";
    const char* const GetGlonassEphDoubleParamForEachSV::Documentation = "Get GLONASS parameter value for all satellites\n"
      "\n"
      "Name      Type   Description\n"
      "--------- ------ ---------------------------------------------------------\n"
      "ParamName string Refer to SetGlonassEphDoubleParamForSV for accepted names";
    const char* const GetGlonassEphDoubleParamForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGlonassEphDoubleParamForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGlonassEphDoubleParamForEachSV);


    GetGlonassEphDoubleParamForEachSV::GetGlonassEphDoubleParamForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetGlonassEphDoubleParamForEachSV::GetGlonassEphDoubleParamForEachSV(const std::string& paramName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
    }

    GetGlonassEphDoubleParamForEachSVPtr GetGlonassEphDoubleParamForEachSV::create(const std::string& paramName)
    {
      return std::make_shared<GetGlonassEphDoubleParamForEachSV>(paramName);
    }

    GetGlonassEphDoubleParamForEachSVPtr GetGlonassEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassEphDoubleParamForEachSV>(ptr);
    }

    bool GetGlonassEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
        ;

    }

    std::string GetGlonassEphDoubleParamForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGlonassEphDoubleParamForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName"}; 
      return names; 
    }


    int GetGlonassEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetGlonassEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGlonassEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
