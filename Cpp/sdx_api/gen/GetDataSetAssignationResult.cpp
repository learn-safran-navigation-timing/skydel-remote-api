
#include "gen/GetDataSetAssignationResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDataSetAssignationResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDataSetAssignationResult::CmdName = "GetDataSetAssignationResult";
    const char* const GetDataSetAssignationResult::Documentation = "Result of GetDataSetAssignation.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetDataSetAssignationResult);


    GetDataSetAssignationResult::GetDataSetAssignationResult()
      : CommandResult(CmdName)
    {}

    GetDataSetAssignationResult::GetDataSetAssignationResult(const std::string& system, const std::string& dataSetType, const std::string& dataSetName)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setDataSetType(dataSetType);
      setDataSetName(dataSetName);
    }

    GetDataSetAssignationResult::GetDataSetAssignationResult(CommandBasePtr relatedCommand, const std::string& system, const std::string& dataSetType, const std::string& dataSetName)
      : CommandResult(CmdName, relatedCommand)
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
