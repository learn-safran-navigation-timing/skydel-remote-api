
#include "GetIntTxBOC.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxBOC
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxBOC::CmdName = "GetIntTxBOC";
    const char* const GetIntTxBOC::Documentation = "Get BOC signal interference.\n"
      "\n"
      "Name          Type   Description\n"
      "------------- ------ ------------------------------\n"
      "TransmitterId string Transmitter unique identifier.\n"
      "SignalId      string BOC unique identifier.";
    const char* const GetIntTxBOC::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIntTxBOC);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIntTxBOC);


    GetIntTxBOC::GetIntTxBOC()
      : CommandBase(CmdName, TargetId)
    {}

    GetIntTxBOC::GetIntTxBOC(const std::string& transmitterId, const std::string& signalId)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetIntTxBOC::fieldNames() const 
    { 
      static const std::vector<std::string> names {"TransmitterId", "SignalId"}; 
      return names; 
    }


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
