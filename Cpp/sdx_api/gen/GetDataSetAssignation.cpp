
#include "GetDataSetAssignation.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetDataSetAssignation
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetDataSetAssignation::CmdName = "GetDataSetAssignation";
    const char* const GetDataSetAssignation::Documentation = "Get data set assignation for the specified constellation.\n"
      "\n"
      "Name        Type   Description\n"
      "----------- ------ -------------------------------------------------------\n"
      "System      string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "DataSetType string \"Almanac\", \"Ephemeris\" or \"Orbit\"";
    const char* const GetDataSetAssignation::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetDataSetAssignation);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetDataSetAssignation);


    GetDataSetAssignation::GetDataSetAssignation()
      : CommandBase(CmdName, TargetId)
    {}

    GetDataSetAssignation::GetDataSetAssignation(const std::string& system, const std::string& dataSetType)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setDataSetType(dataSetType);
    }

    GetDataSetAssignationPtr GetDataSetAssignation::create(const std::string& system, const std::string& dataSetType)
    {
      return std::make_shared<GetDataSetAssignation>(system, dataSetType);
    }

    GetDataSetAssignationPtr GetDataSetAssignation::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetDataSetAssignation>(ptr);
    }

    bool GetDataSetAssignation::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["DataSetType"])
        ;

    }

    std::string GetDataSetAssignation::documentation() const { return Documentation; }

    const std::vector<std::string>& GetDataSetAssignation::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "DataSetType"}; 
      return names; 
    }


    int GetDataSetAssignation::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetDataSetAssignation::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetDataSetAssignation::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetDataSetAssignation::dataSetType() const
    {
      return parse_json<std::string>::parse(m_values["DataSetType"]);
    }

    void GetDataSetAssignation::setDataSetType(const std::string& dataSetType)
    {
      m_values.AddMember("DataSetType", parse_json<std::string>::format(dataSetType, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
