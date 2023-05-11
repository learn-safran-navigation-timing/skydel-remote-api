
#include "gen/SetQzssL1SAugmentation.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetQzssL1SAugmentation
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetQzssL1SAugmentation::CmdName = "SetQzssL1SAugmentation";
    const char* const SetQzssL1SAugmentation::Documentation = "Set Add an augmentation to the L1S navigation messages.";

    REGISTER_COMMAND_FACTORY(SetQzssL1SAugmentation);


    SetQzssL1SAugmentation::SetQzssL1SAugmentation()
      : CommandBase(CmdName)
    {}

    SetQzssL1SAugmentation::SetQzssL1SAugmentation(const std::string& system, int prn, bool augmentIOD, bool augmentPRC, double prc, const std::string& id)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setPrn(prn);
      setAugmentIOD(augmentIOD);
      setAugmentPRC(augmentPRC);
      setPrc(prc);
      setId(id);
    }

    SetQzssL1SAugmentationPtr SetQzssL1SAugmentation::create(const std::string& system, int prn, bool augmentIOD, bool augmentPRC, double prc, const std::string& id)
    {
      return std::make_shared<SetQzssL1SAugmentation>(system, prn, augmentIOD, augmentPRC, prc, id);
    }

    SetQzssL1SAugmentationPtr SetQzssL1SAugmentation::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetQzssL1SAugmentation>(ptr);
    }

    bool SetQzssL1SAugmentation::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<bool>::is_valid(m_values["AugmentIOD"])
          && parse_json<bool>::is_valid(m_values["AugmentPRC"])
          && parse_json<double>::is_valid(m_values["Prc"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetQzssL1SAugmentation::documentation() const { return Documentation; }


    int SetQzssL1SAugmentation::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetQzssL1SAugmentation::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void SetQzssL1SAugmentation::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetQzssL1SAugmentation::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void SetQzssL1SAugmentation::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssL1SAugmentation::augmentIOD() const
    {
      return parse_json<bool>::parse(m_values["AugmentIOD"]);
    }

    void SetQzssL1SAugmentation::setAugmentIOD(bool augmentIOD)
    {
      m_values.AddMember("AugmentIOD", parse_json<bool>::format(augmentIOD, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetQzssL1SAugmentation::augmentPRC() const
    {
      return parse_json<bool>::parse(m_values["AugmentPRC"]);
    }

    void SetQzssL1SAugmentation::setAugmentPRC(bool augmentPRC)
    {
      m_values.AddMember("AugmentPRC", parse_json<bool>::format(augmentPRC, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetQzssL1SAugmentation::prc() const
    {
      return parse_json<double>::parse(m_values["Prc"]);
    }

    void SetQzssL1SAugmentation::setPrc(double prc)
    {
      m_values.AddMember("Prc", parse_json<double>::format(prc, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetQzssL1SAugmentation::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetQzssL1SAugmentation::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
