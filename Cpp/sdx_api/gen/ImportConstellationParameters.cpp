
#include "ImportConstellationParameters.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportConstellationParameters
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportConstellationParameters::CmdName = "ImportConstellationParameters";
    const char* const ImportConstellationParameters::Documentation = "Import navigation message file for the specified constellation. This could be Rinex, SEM or YUMA file for GPS. Only Rinex for the others.\n"
      "\n"
      "Name        Type            Description\n"
      "----------- --------------- -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "System      string          \"GPS\", \"GLONASS\", \"Galileo\", \"SBAS\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Path        string          File path\n"
      "Rollover    optional int    Rollover for file types that does not precise it (YUMA, SEM). Default value is the current rollover.\n"
      "DataSetName optional string Name of the data set to import. This parameter is optional, the default value will be the name of the imported file. Constellations that support this parameter are  \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\" and \"NavIC\"";
    const char* const ImportConstellationParameters::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ImportConstellationParameters);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ImportConstellationParameters);


    ImportConstellationParameters::ImportConstellationParameters()
      : CommandBase(CmdName, TargetId)
    {}

    ImportConstellationParameters::ImportConstellationParameters(const std::string& system, const std::string& path, const Sdx::optional<int>& rollover, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setPath(path);
      setRollover(rollover);
      setDataSetName(dataSetName);
    }

    ImportConstellationParametersPtr ImportConstellationParameters::create(const std::string& system, const std::string& path, const Sdx::optional<int>& rollover, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<ImportConstellationParameters>(system, path, rollover, dataSetName);
    }

    ImportConstellationParametersPtr ImportConstellationParameters::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ImportConstellationParameters>(ptr);
    }

    bool ImportConstellationParameters::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<Sdx::optional<int>>::is_valid(m_values["Rollover"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string ImportConstellationParameters::documentation() const { return Documentation; }

    const std::vector<std::string>& ImportConstellationParameters::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Path", "Rollover", "DataSetName"}; 
      return names; 
    }


    int ImportConstellationParameters::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ImportConstellationParameters::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void ImportConstellationParameters::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ImportConstellationParameters::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ImportConstellationParameters::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> ImportConstellationParameters::rollover() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["Rollover"]);
    }

    void ImportConstellationParameters::setRollover(const Sdx::optional<int>& rollover)
    {
      m_values.AddMember("Rollover", parse_json<Sdx::optional<int>>::format(rollover, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> ImportConstellationParameters::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void ImportConstellationParameters::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
