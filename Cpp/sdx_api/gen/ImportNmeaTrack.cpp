
#include "gen/ImportNmeaTrack.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportNmeaTrack
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportNmeaTrack::CmdName = "ImportNmeaTrack";
    const char* const ImportNmeaTrack::Documentation = "Import NMEA track file";

    REGISTER_COMMAND_FACTORY(ImportNmeaTrack);


    ImportNmeaTrack::ImportNmeaTrack()
      : CommandBase(CmdName)
    {}

    ImportNmeaTrack::ImportNmeaTrack(const std::string& path)
      : CommandBase(CmdName)
    {

      setPath(path);
    }

    ImportNmeaTrackPtr ImportNmeaTrack::create(const std::string& path)
    {
      return std::make_shared<ImportNmeaTrack>(path);
    }

    ImportNmeaTrackPtr ImportNmeaTrack::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ImportNmeaTrack>(ptr);
    }

    bool ImportNmeaTrack::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
        ;

    }

    std::string ImportNmeaTrack::documentation() const { return Documentation; }


    int ImportNmeaTrack::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ImportNmeaTrack::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ImportNmeaTrack::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
