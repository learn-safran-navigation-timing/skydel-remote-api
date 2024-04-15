
#include "GetNavICEphDoubleParamForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICEphDoubleParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICEphDoubleParamForEachSV::CmdName = "GetNavICEphDoubleParamForEachSV";
    const char* const GetNavICEphDoubleParamForEachSV::Documentation = "Please note the command GetNavICEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
      "\n"
      "Get NavIC ephemeris parameter value for all satellites\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetNavICEphDoubleParamForSV for accepted names\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetNavICEphDoubleParamForEachSV::TargetId = "";

    const char* const GetNavICEphDoubleParamForEachSV::Deprecated = "Please note the command GetNavICEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetNavICEphDoubleParamForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNavICEphDoubleParamForEachSV);


    GetNavICEphDoubleParamForEachSV::GetNavICEphDoubleParamForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetNavICEphDoubleParamForEachSV::GetNavICEphDoubleParamForEachSV(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetNavICEphDoubleParamForEachSVPtr GetNavICEphDoubleParamForEachSV::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetNavICEphDoubleParamForEachSV>(paramName, dataSetName);
    }

    GetNavICEphDoubleParamForEachSVPtr GetNavICEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICEphDoubleParamForEachSV>(ptr);
    }

    bool GetNavICEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetNavICEphDoubleParamForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetNavICEphDoubleParamForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "DataSetName"}; 
      return names; 
    }

    Sdx::optional<std::string> GetNavICEphDoubleParamForEachSV::deprecated() const { return Sdx::optional<std::string>{Deprecated}; }


    int GetNavICEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetNavICEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetNavICEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetNavICEphDoubleParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetNavICEphDoubleParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
