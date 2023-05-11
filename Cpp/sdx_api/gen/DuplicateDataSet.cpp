
#include "gen/DuplicateDataSet.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of DuplicateDataSet
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const DuplicateDataSet::CmdName = "DuplicateDataSet";
    const char* const DuplicateDataSet::Documentation = "Duplicate an existing data set.";

    REGISTER_COMMAND_FACTORY(DuplicateDataSet);


    DuplicateDataSet::DuplicateDataSet()
      : CommandBase(CmdName)
    {}

    DuplicateDataSet::DuplicateDataSet(const std::string& system, const std::string& dataSetName, const Sdx::optional<std::string>& newDataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setDataSetName(dataSetName);
      setNewDataSetName(newDataSetName);
    }

    DuplicateDataSetPtr DuplicateDataSet::create(const std::string& system, const std::string& dataSetName, const Sdx::optional<std::string>& newDataSetName)
    {
      return std::make_shared<DuplicateDataSet>(system, dataSetName, newDataSetName);
    }

    DuplicateDataSetPtr DuplicateDataSet::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<DuplicateDataSet>(ptr);
    }

    bool DuplicateDataSet::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["DataSetName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["NewDataSetName"])
        ;

    }

    std::string DuplicateDataSet::documentation() const { return Documentation; }


    int DuplicateDataSet::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string DuplicateDataSet::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void DuplicateDataSet::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string DuplicateDataSet::dataSetName() const
    {
      return parse_json<std::string>::parse(m_values["DataSetName"]);
    }

    void DuplicateDataSet::setDataSetName(const std::string& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::string>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> DuplicateDataSet::newDataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["NewDataSetName"]);
    }

    void DuplicateDataSet::setNewDataSetName(const Sdx::optional<std::string>& newDataSetName)
    {
      m_values.AddMember("NewDataSetName", parse_json<Sdx::optional<std::string>>::format(newDataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
