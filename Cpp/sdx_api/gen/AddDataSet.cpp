
#include "AddDataSet.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of AddDataSet
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const AddDataSet::CmdName = "AddDataSet";
    const char* const AddDataSet::Documentation = "Add a new data set for the specified constellation. This could come from a Rinex, SEM or YUMA file for GPS. Only Rinex for the others.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- --------------------------------------------------------------------------------------------------------------------\n"
      "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Path        string          Data set file path\n"
      "Rollover    optional int    Rollover for file types that does not precise it (YUMA, SEM). Default value is the current rollover.\n"
      "DataSetName optional string Name of the data set to import. This parameter is optional, the default value will be the name of the imported file.";
    const char* const AddDataSet::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(AddDataSet);
    REGISTER_COMMAND_TO_FACTORY_IMPL(AddDataSet);


    AddDataSet::AddDataSet()
      : CommandBase(CmdName, TargetId)
    {}

    AddDataSet::AddDataSet(const std::string& system, const std::string& path, const std::optional<int>& rollover, const std::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setPath(path);
      setRollover(rollover);
      setDataSetName(dataSetName);
    }

    AddDataSetPtr AddDataSet::create(const std::string& system, const std::string& path, const std::optional<int>& rollover, const std::optional<std::string>& dataSetName)
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
          && parse_json<std::optional<int>>::is_valid(m_values["Rollover"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string AddDataSet::documentation() const { return Documentation; }

    const std::vector<std::string>& AddDataSet::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Path", "Rollover", "DataSetName"}; 
      return names; 
    }


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



    std::optional<int> AddDataSet::rollover() const
    {
      return parse_json<std::optional<int>>::parse(m_values["Rollover"]);
    }

    void AddDataSet::setRollover(const std::optional<int>& rollover)
    {
      m_values.AddMember("Rollover", parse_json<std::optional<int>>::format(rollover, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> AddDataSet::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void AddDataSet::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
