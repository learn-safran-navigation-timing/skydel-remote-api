
#include "gen/SetIonoBdgimAlpha.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIonoBdgimAlpha
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIonoBdgimAlpha::CmdName = "SetIonoBdgimAlpha";
    const char* const SetIonoBdgimAlpha::Documentation = "Set the BeiDou (BDGIM) ionospheric Alpha coefficient (in TECu)";

    REGISTER_COMMAND_FACTORY(SetIonoBdgimAlpha);


    SetIonoBdgimAlpha::SetIonoBdgimAlpha()
      : CommandBase(CmdName)
    {}

    SetIonoBdgimAlpha::SetIonoBdgimAlpha(int index, double val)
      : CommandBase(CmdName)
    {

      setIndex(index);
      setVal(val);
    }

    SetIonoBdgimAlphaPtr SetIonoBdgimAlpha::create(int index, double val)
    {
      return std::make_shared<SetIonoBdgimAlpha>(index, val);
    }

    SetIonoBdgimAlphaPtr SetIonoBdgimAlpha::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIonoBdgimAlpha>(ptr);
    }

    bool SetIonoBdgimAlpha::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Index"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string SetIonoBdgimAlpha::documentation() const { return Documentation; }


    int SetIonoBdgimAlpha::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetIonoBdgimAlpha::index() const
    {
      return parse_json<int>::parse(m_values["Index"]);
    }

    void SetIonoBdgimAlpha::setIndex(int index)
    {
      m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIonoBdgimAlpha::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void SetIonoBdgimAlpha::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
