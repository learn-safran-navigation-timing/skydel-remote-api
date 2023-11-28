
#include "gen/GetNavICEphemerisDoubleParams.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICEphemerisDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICEphemerisDoubleParams::CmdName = "GetNavICEphemerisDoubleParams";
    const char* const GetNavICEphemerisDoubleParams::Documentation = "Please note the command GetNavICEphemerisDoubleParams is deprecated since 21.3. You may use GetNavICEphDoubleParamForEachSV.\n\nPlease note the command GetNavICEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n\nGet NavIC ephemeris parameter value for all satellites";

    const char* const GetNavICEphemerisDoubleParams::Deprecated = "Please note the command GetNavICEphemerisDoubleParams is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_FACTORY(GetNavICEphemerisDoubleParams);


    GetNavICEphemerisDoubleParams::GetNavICEphemerisDoubleParams()
      : CommandBase(CmdName)
    {}

    GetNavICEphemerisDoubleParams::GetNavICEphemerisDoubleParams(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetNavICEphemerisDoubleParamsPtr GetNavICEphemerisDoubleParams::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetNavICEphemerisDoubleParams>(paramName, dataSetName);
    }

    GetNavICEphemerisDoubleParamsPtr GetNavICEphemerisDoubleParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICEphemerisDoubleParams>(ptr);
    }

    bool GetNavICEphemerisDoubleParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetNavICEphemerisDoubleParams::documentation() const { return Documentation; }

    Sdx::optional<std::string> GetNavICEphemerisDoubleParams::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetNavICEphemerisDoubleParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetNavICEphemerisDoubleParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetNavICEphemerisDoubleParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetNavICEphemerisDoubleParams::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetNavICEphemerisDoubleParams::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
