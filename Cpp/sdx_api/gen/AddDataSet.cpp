
#include "gen/AddDataSet.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of AddDataSet
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const AddDataSet::CmdName = "AddDataSet";
    const char* const AddDataSet::Documentation = "Add a new data set for the specified constellation. This could come from a Rinex, SEM or YUMA file for GPS. Only Rinex for the others.";

    REGISTER_COMMAND_FACTORY(AddDataSet);


    AddDataSet::AddDataSet()
      : CommandBase(CmdName)
    {}

    AddDataSet::AddDataSet(const std::string& system, const std::string& path, const Sdx::optional<int>& rollover, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPath(path);
      setRollover(rollover);
      setDataSetName(dataSetName);
    }

    AddDataSetPtr AddDataSet::create(const std::string& system, const std::string& path, const Sdx::optional<int>& rollover, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<AddDataSet>(system, path, rollover, dataSetName);
    }

    AddDataSetPtr AddDataSet::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<AddDataSet>(ptr);
    }

    bool AddDataSet::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<Sdx::optional<int>>::is_valid(m_values["Rollover"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string AddDataSet::documentation() const { return Documentation; }


    int AddDataSet::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string AddDataSet::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void AddDataSet::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string AddDataSet::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void AddDataSet::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> AddDataSet::rollover() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Rollover"]);
    }

    void AddDataSet::setRollover(const Sdx::optional<int>& rollover)
    {
      m_values.AddMember("Rollover", parse_json<Sdx::optional<int>>::format(rollover, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> AddDataSet::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void AddDataSet::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
