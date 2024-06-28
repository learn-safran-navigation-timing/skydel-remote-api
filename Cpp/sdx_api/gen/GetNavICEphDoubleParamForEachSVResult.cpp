
#include "GetNavICEphDoubleParamForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNavICEphDoubleParamForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNavICEphDoubleParamForEachSVResult::CmdName = "GetNavICEphDoubleParamForEachSVResult";
    const char* const GetNavICEphDoubleParamForEachSVResult::Documentation = "Result of GetNavICEphDoubleParamForEachSV.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------------------------------------------------------------------------\n"
      "ParamName   string          Refer to SetNavICEphDoubleParamForSV for accepted names\n"
      "Val         array double    Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
    const char* const GetNavICEphDoubleParamForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNavICEphDoubleParamForEachSVResult);


    GetNavICEphDoubleParamForEachSVResult::GetNavICEphDoubleParamForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetNavICEphDoubleParamForEachSVResult::GetNavICEphDoubleParamForEachSVResult(const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    GetNavICEphDoubleParamForEachSVResult::GetNavICEphDoubleParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }


    GetNavICEphDoubleParamForEachSVResultPtr GetNavICEphDoubleParamForEachSVResult::create(const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetNavICEphDoubleParamForEachSVResult>(paramName, val, dataSetName);
    }

    GetNavICEphDoubleParamForEachSVResultPtr GetNavICEphDoubleParamForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetNavICEphDoubleParamForEachSVResult>(relatedCommand, paramName, val, dataSetName);
    }

    GetNavICEphDoubleParamForEachSVResultPtr GetNavICEphDoubleParamForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNavICEphDoubleParamForEachSVResult>(ptr);
    }

    bool GetNavICEphDoubleParamForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetNavICEphDoubleParamForEachSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetNavICEphDoubleParamForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
      return names; 
    }


    std::string GetNavICEphDoubleParamForEachSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetNavICEphDoubleParamForEachSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetNavICEphDoubleParamForEachSVResult::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void GetNavICEphDoubleParamForEachSVResult::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetNavICEphDoubleParamForEachSVResult::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetNavICEphDoubleParamForEachSVResult::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
