
#include "SetNavICEphemerisDoubleParam.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNavICEphemerisDoubleParam
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNavICEphemerisDoubleParam::CmdName = "SetNavICEphemerisDoubleParam";
    const char* const SetNavICEphemerisDoubleParam::Documentation = "Please note the command SetNavICEphemerisDoubleParam is deprecated since 21.3. You may use SetNavICEphDoubleParamForSV.\n"
      "\n"
      "Please note the command SetNavICEphDoubleParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
      "\n"
      "Set various parameters in the NavIC ephemeris\n"
      "\n"
      "  ParamName         Unit\n"
      "  \"ClockBias\"       sec\n"
      "  \"ClockDrift\"      sec/sec\n"
      "  \"ClockDriftRate\"  sec/sec^2\n"
      "  \"Crs\"             meter\n"
      "  \"Crc\"             meter\n"
      "  \"Cis\"             rad\n"
      "  \"Cic\"             rad\n"
      "  \"Cus\"             rad\n"
      "  \"Cuc\"             rad\n"
      "  \"DeltaN\"          rad/sec\n"
      "  \"M0\"              rad\n"
      "  \"Eccentricity\"    -\n"
      "  \"SqrtA\"           sqrt(meter)\n"
      "  \"BigOmega\"        rad\n"
      "  \"I0\"              rad\n"
      "  \"LittleOmega\"     rad\n"
      "  \"BigOmegaDot\"     rad/sec\n"
      "  \"Idot\"            rad/sec\n"
      "  \"Accuracy\"        meter\n"
      "  \"Adot\"            meters/sec\n"
      "  \"DeltaN0dot\"      rad/sec^2\n"
      "  \"Tgd\"             sec\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites\n"
      "ParamName   string          Parameter name (see table above for accepted names)\n"
      "Val         double          Parameter value (see table above for unit)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetNavICEphemerisDoubleParam::TargetId = "";

    const char* const SetNavICEphemerisDoubleParam::Deprecated = "Please note the command SetNavICEphemerisDoubleParam is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetNavICEphemerisDoubleParam);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetNavICEphemerisDoubleParam);


    SetNavICEphemerisDoubleParam::SetNavICEphemerisDoubleParam()
      : CommandBase(CmdName, TargetId)
    {}

    SetNavICEphemerisDoubleParam::SetNavICEphemerisDoubleParam(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetNavICEphemerisDoubleParamPtr SetNavICEphemerisDoubleParam::create(int svId, const std::string& paramName, double val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetNavICEphemerisDoubleParam>(svId, paramName, val, dataSetName);
    }

    SetNavICEphemerisDoubleParamPtr SetNavICEphemerisDoubleParam::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNavICEphemerisDoubleParam>(ptr);
    }

    bool SetNavICEphemerisDoubleParam::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<double>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetNavICEphemerisDoubleParam::documentation() const { return Documentation; }

    const std::vector<std::string>& SetNavICEphemerisDoubleParam::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "ParamName", "Val", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> SetNavICEphemerisDoubleParam::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetNavICEphemerisDoubleParam::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetNavICEphemerisDoubleParam::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetNavICEphemerisDoubleParam::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetNavICEphemerisDoubleParam::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetNavICEphemerisDoubleParam::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetNavICEphemerisDoubleParam::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void SetNavICEphemerisDoubleParam::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetNavICEphemerisDoubleParam::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetNavICEphemerisDoubleParam::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
