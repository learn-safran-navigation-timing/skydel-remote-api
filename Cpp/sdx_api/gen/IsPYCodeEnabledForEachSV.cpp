
#include "IsPYCodeEnabledForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsPYCodeEnabledForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsPYCodeEnabledForEachSV::CmdName = "IsPYCodeEnabledForEachSV";
    const char* const IsPYCodeEnabledForEachSV::Documentation = "Tells if the P(Y)-Code is enabled or disabled for each satellite.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ----------------------------------\n"
      "Signal string Accepted signal keys: \"L1P\", \"L2P\"";
    const char* const IsPYCodeEnabledForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsPYCodeEnabledForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsPYCodeEnabledForEachSV);


    IsPYCodeEnabledForEachSV::IsPYCodeEnabledForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    IsPYCodeEnabledForEachSV::IsPYCodeEnabledForEachSV(const std::string& signal)
      : CommandBase(CmdName, TargetId)
    {

      setSignal(signal);
    }

    IsPYCodeEnabledForEachSVPtr IsPYCodeEnabledForEachSV::create(const std::string& signal)
    {
      return std::make_shared<IsPYCodeEnabledForEachSV>(signal);
    }

    IsPYCodeEnabledForEachSVPtr IsPYCodeEnabledForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsPYCodeEnabledForEachSV>(ptr);
    }

    bool IsPYCodeEnabledForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string IsPYCodeEnabledForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& IsPYCodeEnabledForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Signal"}; 
      return names; 
    }


    int IsPYCodeEnabledForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsPYCodeEnabledForEachSV::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsPYCodeEnabledForEachSV::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
