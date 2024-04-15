
#include "GetIonoBeta.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoBeta
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoBeta::CmdName = "GetIonoBeta";
    const char* const GetIonoBeta::Documentation = "Get the GPS ionospheric Beta coefficient\n"
      "Beta 0 is in seconds\n"
      "Beta 1 is in seconds/semicircle\n"
      "Beta 2 is in seconds/semicircle^2\n"
      "Beta 3 is in seconds/semicircle^3\n"
      "\n"
      "Name  Type Description\n"
      "----- ---- ------------------------\n"
      "Index int  Coefficient index [0..3]";
    const char* const GetIonoBeta::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIonoBeta);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIonoBeta);


    GetIonoBeta::GetIonoBeta()
      : CommandBase(CmdName, TargetId)
    {}

    GetIonoBeta::GetIonoBeta(int index)
      : CommandBase(CmdName, TargetId)
    {

      setIndex(index);
    }

    GetIonoBetaPtr GetIonoBeta::create(int index)
    {
      return std::make_shared<GetIonoBeta>(index);
    }

    GetIonoBetaPtr GetIonoBeta::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoBeta>(ptr);
    }

    bool GetIonoBeta::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Index"])
        ;

    }

    std::string GetIonoBeta::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIonoBeta::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Index"}; 
      return names; 
    }


    int GetIonoBeta::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetIonoBeta::index() const
    {
      return parse_json<int>::parse(m_values["Index"]);
    }

    void GetIonoBeta::setIndex(int index)
    {
      m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
