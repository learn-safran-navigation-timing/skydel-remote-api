
#include "GetAllMultipathForSignal.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllMultipathForSignal
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllMultipathForSignal::CmdName = "GetAllMultipathForSignal";
    const char* const GetAllMultipathForSignal::Documentation = "Get all multipath ID for the specified signal.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------------------------------------------------------------\n"
      "Signal string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
      "                                    \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\",\n"
      "                                    \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\",\n"
      "                                    \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\" and \"PULSARX1\"";
    const char* const GetAllMultipathForSignal::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetAllMultipathForSignal);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAllMultipathForSignal);


    GetAllMultipathForSignal::GetAllMultipathForSignal()
      : CommandBase(CmdName, TargetId)
    {}

    GetAllMultipathForSignal::GetAllMultipathForSignal(const std::string& signal)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
    }

    GetAllMultipathForSignalPtr GetAllMultipathForSignal::create(const std::string& signal)
    {
      return std::make_shared<GetAllMultipathForSignal>(signal);
    }

    GetAllMultipathForSignalPtr GetAllMultipathForSignal::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllMultipathForSignal>(ptr);
    }

    bool GetAllMultipathForSignal::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string GetAllMultipathForSignal::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAllMultipathForSignal::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal"}; 
      return names; 
    }


    int GetAllMultipathForSignal::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetAllMultipathForSignal::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetAllMultipathForSignal::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
