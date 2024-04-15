
#include "SetNavICEphemerisDoubleParams.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNavICEphemerisDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNavICEphemerisDoubleParams::CmdName = "SetNavICEphemerisDoubleParams";
    const char* const SetNavICEphemerisDoubleParams::Documentation = "Please note the command SetNavICEphemerisDoubleParams is deprecated since 21.3. You may use SetNavICEphDoubleParamForEachSV.\n"
      "\n"
      "Please note the command SetNavICEphDoubleParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
      "\n"
      "Set NavIC ephemeris parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetNavICEphDoubleParamForSV for accepted names\n"
      "Val         array double    Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetNavICEphemerisDoubleParams::TargetId = "";

    const char* const SetNavICEphemerisDoubleParams::Deprecated = "Please note the command SetNavICEphemerisDoubleParams is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetNavICEphemerisDoubleParams);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetNavICEphemerisDoubleParams);


    SetNavICEphemerisDoubleParams::SetNavICEphemerisDoubleParams()
      : CommandBase(CmdName, TargetId)
    {}

    SetNavICEphemerisDoubleParams::SetNavICEphemerisDoubleParams(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetNavICEphemerisDoubleParamsPtr SetNavICEphemerisDoubleParams::create(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetNavICEphemerisDoubleParams>(paramName, val, dataSetName);
    }

    SetNavICEphemerisDoubleParamsPtr SetNavICEphemerisDoubleParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNavICEphemerisDoubleParams>(ptr);
    }

    bool SetNavICEphemerisDoubleParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetNavICEphemerisDoubleParams::documentation() const { return Documentation; }

    const std::vector<std::string>& SetNavICEphemerisDoubleParams::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> SetNavICEphemerisDoubleParams::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetNavICEphemerisDoubleParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetNavICEphemerisDoubleParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetNavICEphemerisDoubleParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetNavICEphemerisDoubleParams::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void SetNavICEphemerisDoubleParams::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetNavICEphemerisDoubleParams::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetNavICEphemerisDoubleParams::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
