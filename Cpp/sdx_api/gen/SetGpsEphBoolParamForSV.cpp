
#include "gen/SetGpsEphBoolParamForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsEphBoolParamForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsEphBoolParamForSV::CmdName = "SetGpsEphBoolParamForSV";
    const char* const SetGpsEphBoolParamForSV::Documentation = "Set various boolean parameters in the GPS ephemeris\n\n  ParamName\n\"IscL1CaAvailable\"\n\"IscL2CAvailable\"\n\"IscL5I5Available\"\n\"IscL5Q5Available\"\n\"IscL1CPAvailable\"\n\"IscL1CDAvailable\"";

    REGISTER_COMMAND_FACTORY(SetGpsEphBoolParamForSV);


    SetGpsEphBoolParamForSV::SetGpsEphBoolParamForSV()
      : CommandBase(CmdName)
    {}

    SetGpsEphBoolParamForSV::SetGpsEphBoolParamForSV(int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetGpsEphBoolParamForSVPtr SetGpsEphBoolParamForSV::create(int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetGpsEphBoolParamForSV>(svId, paramName, val, dataSetName);
    }

    SetGpsEphBoolParamForSVPtr SetGpsEphBoolParamForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsEphBoolParamForSV>(ptr);
    }

    bool SetGpsEphBoolParamForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<bool>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetGpsEphBoolParamForSV::documentation() const { return Documentation; }


    int SetGpsEphBoolParamForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetGpsEphBoolParamForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetGpsEphBoolParamForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetGpsEphBoolParamForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGpsEphBoolParamForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetGpsEphBoolParamForSV::val() const
    {
      return parse_json<bool>::parse(m_values["Val"]);
    }

    void SetGpsEphBoolParamForSV::setVal(bool val)
    {
      m_values.AddMember("Val", parse_json<bool>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetGpsEphBoolParamForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetGpsEphBoolParamForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
