
#include "gen/GetIntTxIqFile.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxIqFile
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxIqFile::CmdName = "GetIntTxIqFile";
    const char* const GetIntTxIqFile::Documentation = "Get IQ file signal interference.";

    REGISTER_COMMAND_FACTORY(GetIntTxIqFile);


    GetIntTxIqFile::GetIntTxIqFile()
      : CommandBase(CmdName)
    {}

    GetIntTxIqFile::GetIntTxIqFile(const std::string& transmitterId, const std::string& signalId)
      : CommandBase(CmdName)
    {

      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    GetIntTxIqFilePtr GetIntTxIqFile::create(const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetIntTxIqFile>(transmitterId, signalId);
    }

    GetIntTxIqFilePtr GetIntTxIqFile::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxIqFile>(ptr);
    }

    bool GetIntTxIqFile::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string GetIntTxIqFile::documentation() const { return Documentation; }


    int GetIntTxIqFile::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxIqFile::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxIqFile::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxIqFile::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxIqFile::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
