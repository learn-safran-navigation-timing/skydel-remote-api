
#include "GetActiveDataSetResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetActiveDataSetResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetActiveDataSetResult::CmdName = "GetActiveDataSetResult";
    const char* const GetActiveDataSetResult::Documentation = "Result of GetActiveDataSet.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ -------------------------------------------------------\n"
      "System      string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "DataSetName string The name of the data set to set as active.";
    const char* const GetActiveDataSetResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetActiveDataSetResult);


    GetActiveDataSetResult::GetActiveDataSetResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetActiveDataSetResult::GetActiveDataSetResult(const std::string& system, const std::string& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setDataSetName(dataSetName);
    }

    GetActiveDataSetResult::GetActiveDataSetResult(CommandBasePtr relatedCommand, const std::string& system, const std::string& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setDataSetName(dataSetName);
    }


    GetActiveDataSetResultPtr GetActiveDataSetResult::create(const std::string& system, const std::string& dataSetName)
    {
      return std::make_shared<GetActiveDataSetResult>(system, dataSetName);
    }

    GetActiveDataSetResultPtr GetActiveDataSetResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::string& dataSetName)
    {
      return std::make_shared<GetActiveDataSetResult>(relatedCommand, system, dataSetName);
    }

    GetActiveDataSetResultPtr GetActiveDataSetResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetActiveDataSetResult>(ptr);
    }

    bool GetActiveDataSetResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetActiveDataSetResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetActiveDataSetResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "DataSetName"}; 
      return names; 
    }


    std::string GetActiveDataSetResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetActiveDataSetResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetActiveDataSetResult::dataSetName() const
    {
      return parse_json<std::string>::parse(m_values["DataSetName"]);
    }

    void GetActiveDataSetResult::setDataSetName(const std::string& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::string>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
