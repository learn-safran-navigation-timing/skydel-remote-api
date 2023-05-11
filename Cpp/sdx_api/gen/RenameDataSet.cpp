
#include "gen/RenameDataSet.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of RenameDataSet
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RenameDataSet::CmdName = "RenameDataSet";
    const char* const RenameDataSet::Documentation = "Rename data set.";

    REGISTER_COMMAND_FACTORY(RenameDataSet);


    RenameDataSet::RenameDataSet()
      : CommandBase(CmdName)
    {}

    RenameDataSet::RenameDataSet(const std::string& system, const std::string& dataSetName, const std::string& newDataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setDataSetName(dataSetName);
      setNewDataSetName(newDataSetName);
    }

    RenameDataSetPtr RenameDataSet::create(const std::string& system, const std::string& dataSetName, const std::string& newDataSetName)
    {
      return std::make_shared<RenameDataSet>(system, dataSetName, newDataSetName);
    }

    RenameDataSetPtr RenameDataSet::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RenameDataSet>(ptr);
    }

    bool RenameDataSet::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["DataSetName"])
          && parse_json<std::string>::is_valid(m_values["NewDataSetName"])
        ;

    }

    std::string RenameDataSet::documentation() const { return Documentation; }


    int RenameDataSet::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RenameDataSet::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void RenameDataSet::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RenameDataSet::dataSetName() const
    {
      return parse_json<std::string>::parse(m_values["DataSetName"]);
    }

    void RenameDataSet::setDataSetName(const std::string& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::string>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string RenameDataSet::newDataSetName() const
    {
      return parse_json<std::string>::parse(m_values["NewDataSetName"]);
    }

    void RenameDataSet::setNewDataSetName(const std::string& newDataSetName)
    {
      m_values.AddMember("NewDataSetName", parse_json<std::string>::format(newDataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
