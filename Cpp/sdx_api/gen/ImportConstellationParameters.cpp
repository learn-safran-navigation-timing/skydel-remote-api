
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
    const char* const ImportConstellationParameters::Documentation = "Import navigation message file for the specified constellation. This could be RINEX, SEM or YUMA file for GPS. Only RINEX for the others.\n"
      "\n"
      "Name         Type            Description\n"
      "------------ --------------- ----------------------------------------------------------------------------------------------------------------------\n"
      "System       string          \"GPS\", \"GLONASS\", \"Galileo\", \"SBAS\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "Path         string          File path\n"
      "Rollover     optional int    Rollover for file types that does not precise it (YUMA, SEM). Default value is the current rollover.\n"
      "DataSetName  optional string Name of the data set to import. This parameter is optional, the default value will be the name of the imported file.\n"
      "                             Constellations that support this parameter are  \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\" and \"NavIC\".\n"
      "NavMsgFamily optional string Navigation message family key used to specify which ephemeris navigation message type to import from a RINEX v4+ file.\n"
      "                             This parameter is optional and ignored for other file formats. Default values are: \"GPS_LNAV\" for GPS,\n"
      "                             \"GALILEO_FNAV\" for Galileo, \"BEIDOU_D1_NAV\" for BeiDou, \"QZSS_LNAV\" for QZSS and \"NAVIC_NAV\" for NavIC.\n"
      "                             Accepted values are: \"GPS_LNAV\", \"GPS_CNAV\", \"GALILEO_FNAV\", \"GALILEO_INAV\", \"BEIDOU_D1_NAV\", \"BEIDOU_D2_NAV\",\n"
      "                             \"QZSS_LNAV\" and \"NAVIC_NAV\".";
    const char* const ImportConstellationParameters::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ImportConstellationParameters);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ImportConstellationParameters);


    ImportConstellationParameters::ImportConstellationParameters()
      : CommandBase(CmdName, TargetId)
    {}

    ImportConstellationParameters::ImportConstellationParameters(const std::string& system, const std::string& path, const std::optional<int>& rollover, const std::optional<std::string>& dataSetName, const std::optional<std::string>& navMsgFamily)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setPath(path);
      setRollover(rollover);
      setDataSetName(dataSetName);
      setNavMsgFamily(navMsgFamily);
    }

    ImportConstellationParametersPtr ImportConstellationParameters::create(const std::string& system, const std::string& path, const std::optional<int>& rollover, const std::optional<std::string>& dataSetName, const std::optional<std::string>& navMsgFamily)
    {
      return std::make_shared<ImportConstellationParameters>(system, path, rollover, dataSetName, navMsgFamily);
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
          && parse_json<std::optional<int>>::is_valid(m_values["Rollover"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["NavMsgFamily"])
        ;

    }

    std::string ImportConstellationParameters::documentation() const { return Documentation; }

    const std::vector<std::string>& ImportConstellationParameters::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "Path", "Rollover", "DataSetName", "NavMsgFamily"}; 
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



    std::optional<int> ImportConstellationParameters::rollover() const
    {
      return parse_json<std::optional<int>>::parse(m_values["Rollover"]);
    }

    void ImportConstellationParameters::setRollover(const std::optional<int>& rollover)
    {
      m_values.AddMember("Rollover", parse_json<std::optional<int>>::format(rollover, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> ImportConstellationParameters::dataSetName() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void ImportConstellationParameters::setDataSetName(const std::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> ImportConstellationParameters::navMsgFamily() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["NavMsgFamily"]);
    }

    void ImportConstellationParameters::setNavMsgFamily(const std::optional<std::string>& navMsgFamily)
    {
      m_values.AddMember("NavMsgFamily", parse_json<std::optional<std::string>>::format(navMsgFamily, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
