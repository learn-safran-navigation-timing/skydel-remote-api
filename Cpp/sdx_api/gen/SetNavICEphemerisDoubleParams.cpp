
#include "gen/SetNavICEphemerisDoubleParams.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetNavICEphemerisDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetNavICEphemerisDoubleParams::CmdName = "SetNavICEphemerisDoubleParams";
    const char* const SetNavICEphemerisDoubleParams::Documentation = "Please note the command SetNavICEphemerisDoubleParams is deprecated since 21.3. You may use SetNavICEphDoubleParamForEachSV.\n\nSet NavIC ephemeris parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(SetNavICEphemerisDoubleParams);


    SetNavICEphemerisDoubleParams::SetNavICEphemerisDoubleParams()
      : CommandBase(CmdName)
    {}

    SetNavICEphemerisDoubleParams::SetNavICEphemerisDoubleParams(const std::string& paramName, const std::vector<double>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
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
