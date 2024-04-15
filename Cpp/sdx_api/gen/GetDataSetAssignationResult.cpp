
#include "GetDataSetAssignationResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDataSetAssignationResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDataSetAssignationResult::CmdName = "GetDataSetAssignationResult";
    const char* const GetDataSetAssignationResult::Documentation = "Result of GetDataSetAssignation.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ -------------------------------------------------------\n"
      "System      string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "DataSetType string \"Almanac\", \"Ephemeris\" or \"Orbit\"\n"
      "DataSetName string The name of the assigned data set.";
    const char* const GetDataSetAssignationResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetDataSetAssignationResult);


    GetDataSetAssignationResult::GetDataSetAssignationResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetDataSetAssignationResult::GetDataSetAssignationResult(const std::string& system, const std::string& dataSetType, const std::string& dataSetName)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setDataSetType(dataSetType);
      setDataSetName(dataSetName);
    }

    GetDataSetAssignationResult::GetDataSetAssignationResult(CommandBasePtr relatedCommand, const std::string& system, const std::string& dataSetType, const std::string& dataSetName)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setDataSetType(dataSetType);
      setDataSetName(dataSetName);
    }


    GetDataSetAssignationResultPtr GetDataSetAssignationResult::create(const std::string& system, const std::string& dataSetType, const std::string& dataSetName)
    {
      return std::make_shared<GetDataSetAssignationResult>(system, dataSetType, dataSetName);
    }

    GetDataSetAssignationResultPtr GetDataSetAssignationResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::string& dataSetType, const std::string& dataSetName)
    {
      return std::make_shared<GetDataSetAssignationResult>(relatedCommand, system, dataSetType, dataSetName);
    }

    GetDataSetAssignationResultPtr GetDataSetAssignationResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetDataSetAssignationResult>(ptr);
    }

    bool GetDataSetAssignationResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["DataSetType"])
          && parse_json<std::string>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetDataSetAssignationResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetDataSetAssignationResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "DataSetType", "DataSetName"}; 
      return names; 
    }


    std::string GetDataSetAssignationResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetDataSetAssignationResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetDataSetAssignationResult::dataSetType() const
    {
      return parse_json<std::string>::parse(m_values["DataSetType"]);
    }

    void GetDataSetAssignationResult::setDataSetType(const std::string& dataSetType)
    {
      m_values.AddMember("DataSetType", parse_json<std::string>::format(dataSetType, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetDataSetAssignationResult::dataSetName() const
    {
      return parse_json<std::string>::parse(m_values["DataSetName"]);
    }

    void GetDataSetAssignationResult::setDataSetName(const std::string& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::string>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
