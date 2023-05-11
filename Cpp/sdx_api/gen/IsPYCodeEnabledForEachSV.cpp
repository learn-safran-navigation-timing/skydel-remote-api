
#include "gen/IsPYCodeEnabledForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsPYCodeEnabledForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsPYCodeEnabledForEachSV::CmdName = "IsPYCodeEnabledForEachSV";
    const char* const IsPYCodeEnabledForEachSV::Documentation = "Tells if the P(Y)-Code is enabled or disabled for each satellite.";

    REGISTER_COMMAND_FACTORY(IsPYCodeEnabledForEachSV);


    IsPYCodeEnabledForEachSV::IsPYCodeEnabledForEachSV()
      : CommandBase(CmdName)
    {}

    IsPYCodeEnabledForEachSV::IsPYCodeEnabledForEachSV(const std::string& signal)
      : CommandBase(CmdName)
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
