
#include "GetAllMessageModificationIdsForSignal.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllMessageModificationIdsForSignal
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllMessageModificationIdsForSignal::CmdName = "GetAllMessageModificationIdsForSignal";
    const char* const GetAllMessageModificationIdsForSignal::Documentation = "Get all the message modification event's IDs for this signal and SV ID.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ---------------------------------------------------------------------------------------------------------\n"
      "Signal string Signal key, accepted values : \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
      "                                            \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B2a\", \"B1C\", \"B3I\",\n"
      "                                            \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1S\", \"NAVICL5\", \"NAVICS\", \"SBASL1\", \"SBASL5\",\n"
      "                                            \"PULSARXL\" and \"PULSARX1\"\n"
      "SvId   int    The satellite's SV ID";
    const char* const GetAllMessageModificationIdsForSignal::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllMessageModificationIdsForSignal);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllMessageModificationIdsForSignal);


    GetAllMessageModificationIdsForSignal::GetAllMessageModificationIdsForSignal()
      : CommandBase(CmdName, TargetId)
    {}

    GetAllMessageModificationIdsForSignal::GetAllMessageModificationIdsForSignal(const std::string& signal, int svId)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
      setSvId(svId);
    }

    GetAllMessageModificationIdsForSignalPtr GetAllMessageModificationIdsForSignal::create(const std::string& signal, int svId)
    {
      return std::make_shared<GetAllMessageModificationIdsForSignal>(signal, svId);
    }

    GetAllMessageModificationIdsForSignalPtr GetAllMessageModificationIdsForSignal::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllMessageModificationIdsForSignal>(ptr);
    }

    bool GetAllMessageModificationIdsForSignal::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetAllMessageModificationIdsForSignal::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAllMessageModificationIdsForSignal::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal", "SvId"}; 
      return names; 
    }


    int GetAllMessageModificationIdsForSignal::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetAllMessageModificationIdsForSignal::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetAllMessageModificationIdsForSignal::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetAllMessageModificationIdsForSignal::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetAllMessageModificationIdsForSignal::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
