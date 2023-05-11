
#include "gen/GetGlonassEphDoubleParamForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassEphDoubleParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassEphDoubleParamForEachSV::CmdName = "GetGlonassEphDoubleParamForEachSV";
    const char* const GetGlonassEphDoubleParamForEachSV::Documentation = "Get GLONASS parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(GetGlonassEphDoubleParamForEachSV);


    GetGlonassEphDoubleParamForEachSV::GetGlonassEphDoubleParamForEachSV()
      : CommandBase(CmdName)
    {}

    GetGlonassEphDoubleParamForEachSV::GetGlonassEphDoubleParamForEachSV(const std::string& paramName)
      : CommandBase(CmdName)
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
