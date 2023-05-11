
#include "gen/SetDataSetAssignation.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetDataSetAssignation
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetDataSetAssignation::CmdName = "SetDataSetAssignation";
    const char* const SetDataSetAssignation::Documentation = "Set data set assignation for the specified constellation.";

    REGISTER_COMMAND_FACTORY(SetDataSetAssignation);


    SetDataSetAssignation::SetDataSetAssignation()
      : CommandBase(CmdName)
    {}

    SetDataSetAssignation::SetDataSetAssignation(const std::string& system, const std::string& dataSetType, const std::string& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setDataSetType(dataSetType);
      setDataSetName(dataSetName);
    }

    SetDataSetAssignationPtr SetDataSetAssignation::create(const std::string& system, const std::string& dataSetType, const std::string& dataSetName)
    {
      return std::make_shared<SetDataSetAssignation>(system, dataSetType, dataSetName);
    }

    SetDataSetAssignationPtr SetDataSetAssignation::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetDataSetAssignation>(ptr);
    }

    bool SetDataSetAssignation::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["DataSetType"])
          && parse_json<std::string>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetDataSetAssignation::documentation() const { return Documentation; }


    int SetDataSetAssignation::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetDataSetAssignation::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetDataSetAssignation::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetDataSetAssignation::dataSetType() const
    {
      return parse_json<std::string>::parse(m_values["DataSetType"]);
    }

    void SetDataSetAssignation::setDataSetType(const std::string& dataSetType)
    {
      m_values.AddMember("DataSetType", parse_json<std::string>::format(dataSetType, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetDataSetAssignation::dataSetName() const
    {
      return parse_json<std::string>::parse(m_values["DataSetName"]);
    }

    void SetDataSetAssignation::setDataSetName(const std::string& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::string>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
