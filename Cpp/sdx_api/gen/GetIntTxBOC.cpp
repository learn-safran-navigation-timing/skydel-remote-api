
#include "gen/GetIntTxBOC.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxBOC
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxBOC::CmdName = "GetIntTxBOC";
    const char* const GetIntTxBOC::Documentation = "Get BOC signal interference.";

    REGISTER_COMMAND_FACTORY(GetIntTxBOC);


    GetIntTxBOC::GetIntTxBOC()
      : CommandBase(CmdName)
    {}

    GetIntTxBOC::GetIntTxBOC(const std::string& transmitterId, const std::string& signalId)
      : CommandBase(CmdName)
    {

      setTransmitterId(transmitterId);
      setSignalId(signalId);
    }

    GetIntTxBOCPtr GetIntTxBOC::create(const std::string& transmitterId, const std::string& signalId)
    {
      return std::make_shared<GetIntTxBOC>(transmitterId, signalId);
    }

    GetIntTxBOCPtr GetIntTxBOC::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxBOC>(ptr);
    }

    bool GetIntTxBOC::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["TransmitterId"])
          && parse_json<std::string>::is_valid(m_values["SignalId"])
        ;

    }

    std::string GetIntTxBOC::documentation() const { return Documentation; }


    int GetIntTxBOC::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIntTxBOC::transmitterId() const
    {
      return parse_json<std::string>::parse(m_values["TransmitterId"]);
    }

    void GetIntTxBOC::setTransmitterId(const std::string& transmitterId)
    {
      m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxBOC::signalId() const
    {
      return parse_json<std::string>::parse(m_values["SignalId"]);
    }

    void GetIntTxBOC::setSignalId(const std::string& signalId)
    {
      m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
