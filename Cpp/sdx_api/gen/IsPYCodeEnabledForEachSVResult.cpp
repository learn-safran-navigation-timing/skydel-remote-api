
#include "gen/IsPYCodeEnabledForEachSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsPYCodeEnabledForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsPYCodeEnabledForEachSVResult::CmdName = "IsPYCodeEnabledForEachSVResult";
    const char* const IsPYCodeEnabledForEachSVResult::Documentation = "Result of IsPYCodeEnabledForEachSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(IsPYCodeEnabledForEachSVResult);


    IsPYCodeEnabledForEachSVResult::IsPYCodeEnabledForEachSVResult()
      : CommandResult(CmdName)
    {}

    IsPYCodeEnabledForEachSVResult::IsPYCodeEnabledForEachSVResult(const std::string& signal, const std::vector<bool>& enabled)
      : CommandResult(CmdName)
    {

      setSignal(signal);
      setEnabled(enabled);
    }

    IsPYCodeEnabledForEachSVResult::IsPYCodeEnabledForEachSVResult(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<bool>& enabled)
      : CommandResult(CmdName, relatedCommand)
    {

      setSignal(signal);
      setEnabled(enabled);
    }


    IsPYCodeEnabledForEachSVResultPtr IsPYCodeEnabledForEachSVResult::create(const std::string& signal, const std::vector<bool>& enabled)
    {
      return std::make_shared<IsPYCodeEnabledForEachSVResult>(signal, enabled);
    }

    IsPYCodeEnabledForEachSVResultPtr IsPYCodeEnabledForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<bool>& enabled)
    {
      return std::make_shared<IsPYCodeEnabledForEachSVResult>(relatedCommand, signal, enabled);
    }

    IsPYCodeEnabledForEachSVResultPtr IsPYCodeEnabledForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsPYCodeEnabledForEachSVResult>(ptr);
    }

    bool IsPYCodeEnabledForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
        ;

    }

    std::string IsPYCodeEnabledForEachSVResult::documentation() const { return Documentation; }


    std::string IsPYCodeEnabledForEachSVResult::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsPYCodeEnabledForEachSVResult::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> IsPYCodeEnabledForEachSVResult::enabled() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
    }

    void IsPYCodeEnabledForEachSVResult::setEnabled(const std::vector<bool>& enabled)
    {
      m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
