
#include "SetNavICEphDoubleParamForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNavICEphDoubleParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNavICEphDoubleParamForEachSV::CmdName = "SetNavICEphDoubleParamForEachSV";
    const char* const SetNavICEphDoubleParamForEachSV::Documentation = "Please note the command SetNavICEphDoubleParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
      "\n"
      "Set NavIC ephemeris parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetNavICEphDoubleParamForSV for accepted names\n"
      "Val         array double    Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const SetNavICEphDoubleParamForEachSV::TargetId = "";

    const char* const SetNavICEphDoubleParamForEachSV::Deprecated = "Please note the command SetNavICEphDoubleParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetNavICEphDoubleParamForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetNavICEphDoubleParamForEachSV);


    SetNavICEphDoubleParamForEachSV::SetNavICEphDoubleParamForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetNavICEphDoubleParamForEachSV::SetNavICEphDoubleParamForEachSV(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetNavICEphDoubleParamForEachSVPtr SetNavICEphDoubleParamForEachSV::create(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetNavICEphDoubleParamForEachSV>(paramName, val, dataSetName);
    }

    SetNavICEphDoubleParamForEachSVPtr SetNavICEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetNavICEphDoubleParamForEachSV>(ptr);
    }

    bool SetNavICEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetNavICEphDoubleParamForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetNavICEphDoubleParamForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> SetNavICEphDoubleParamForEachSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int SetNavICEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetNavICEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetNavICEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetNavICEphDoubleParamForEachSV::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void SetNavICEphDoubleParamForEachSV::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetNavICEphDoubleParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetNavICEphDoubleParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
