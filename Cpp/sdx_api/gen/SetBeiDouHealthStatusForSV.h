#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set BeiDou satellite health status
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------------------
    /// SvId   int  Satellite SV ID 1..35
    /// Health int  Health Info, 2-bit integer : 0, 1, 2 or 3
    ///

    class SetBeiDouHealthStatusForSV;
    typedef std::shared_ptr<SetBeiDouHealthStatusForSV> SetBeiDouHealthStatusForSVPtr;
    
    
    class SetBeiDouHealthStatusForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetBeiDouHealthStatusForSV();

      SetBeiDouHealthStatusForSV(int svId, int health);
  
      static SetBeiDouHealthStatusForSVPtr create(int svId, int health);
      static SetBeiDouHealthStatusForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      int health() const;
      void setHealth(int health);
    };
  }
}

