
#include "ImportNmeaSpoofTxTrack.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportNmeaSpoofTxTrack
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportNmeaSpoofTxTrack::CmdName = "ImportNmeaSpoofTxTrack";
    const char* const ImportNmeaSpoofTxTrack::Documentation = "Import NMEA spoofer transmitter track file.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Path string NMEA file path.\n"
      "Id   string Transmitter unique identifier.";
    const char* const ImportNmeaSpoofTxTrack::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ImportNmeaSpoofTxTrack);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ImportNmeaSpoofTxTrack);


    ImportNmeaSpoofTxTrack::ImportNmeaSpoofTxTrack()
      : CommandBase(CmdName, TargetId)
    {}

    ImportNmeaSpoofTxTrack::ImportNmeaSpoofTxTrack(const std::string& path, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setPath(path);
      setId(id);
    }

    ImportNmeaSpoofTxTrackPtr ImportNmeaSpoofTxTrack::create(const std::string& path, const std::string& id)
    {
      return std::make_shared<ImportNmeaSpoofTxTrack>(path, id);
    }

    ImportNmeaSpoofTxTrackPtr ImportNmeaSpoofTxTrack::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ImportNmeaSpoofTxTrack>(ptr);
    }

    bool ImportNmeaSpoofTxTrack::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string ImportNmeaSpoofTxTrack::documentation() const { return Documentation; }

    const std::vector<std::string>& ImportNmeaSpoofTxTrack::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Path", "Id"}; 
      return names; 
    }


    int ImportNmeaSpoofTxTrack::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ImportNmeaSpoofTxTrack::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ImportNmeaSpoofTxTrack::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ImportNmeaSpoofTxTrack::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void ImportNmeaSpoofTxTrack::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
