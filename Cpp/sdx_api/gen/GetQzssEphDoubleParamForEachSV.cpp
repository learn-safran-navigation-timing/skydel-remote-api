
#include "gen/GetQzssEphDoubleParamForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphDoubleParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphDoubleParamForEachSV::CmdName = "GetQzssEphDoubleParamForEachSV";
    const char* const GetQzssEphDoubleParamForEachSV::Documentation = "Get QZSS ephemeris parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(GetQzssEphDoubleParamForEachSV);


    GetQzssEphDoubleParamForEachSV::GetQzssEphDoubleParamForEachSV()
      : CommandBase(CmdName)
    {}

    GetQzssEphDoubleParamForEachSV::GetQzssEphDoubleParamForEachSV(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetQzssEphDoubleParamForEachSVPtr GetQzssEphDoubleParamForEachSV::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphDoubleParamForEachSV>(paramName, dataSetName);
    }

    GetQzssEphDoubleParamForEachSVPtr GetQzssEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphDoubleParamForEachSV>(ptr);
    }

    bool GetQzssEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphDoubleParamForEachSV::documentation() const { return Documentation; }


    int GetQzssEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetQzssEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssEphDoubleParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphDoubleParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
