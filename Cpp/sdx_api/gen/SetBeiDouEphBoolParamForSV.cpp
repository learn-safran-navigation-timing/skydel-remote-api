
#include "gen/SetBeiDouEphBoolParamForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouEphBoolParamForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouEphBoolParamForSV::CmdName = "SetBeiDouEphBoolParamForSV";
    const char* const SetBeiDouEphBoolParamForSV::Documentation = "Set various boolean parameters in the BeiDou ephemeris\n\n  ParamName\n\"IscB1CdAvailable\"\n\"IscB2adAvailable\"";

    REGISTER_COMMAND_FACTORY(SetBeiDouEphBoolParamForSV);


    SetBeiDouEphBoolParamForSV::SetBeiDouEphBoolParamForSV()
      : CommandBase(CmdName)
    {}

    SetBeiDouEphBoolParamForSV::SetBeiDouEphBoolParamForSV(int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetBeiDouEphBoolParamForSVPtr SetBeiDouEphBoolParamForSV::create(int svId, const std::string& paramName, bool val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetBeiDouEphBoolParamForSV>(svId, paramName, val, dataSetName);
    }

    SetBeiDouEphBoolParamForSVPtr SetBeiDouEphBoolParamForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouEphBoolParamForSV>(ptr);
    }

    bool SetBeiDouEphBoolParamForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<bool>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetBeiDouEphBoolParamForSV::documentation() const { return Documentation; }


    int SetBeiDouEphBoolParamForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetBeiDouEphBoolParamForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetBeiDouEphBoolParamForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetBeiDouEphBoolParamForSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetBeiDouEphBoolParamForSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetBeiDouEphBoolParamForSV::val() const
    {
      return parse_json<bool>::parse(m_values["Val"]);
    }

    void SetBeiDouEphBoolParamForSV::setVal(bool val)
    {
      m_values.AddMember("Val", parse_json<bool>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetBeiDouEphBoolParamForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetBeiDouEphBoolParamForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
