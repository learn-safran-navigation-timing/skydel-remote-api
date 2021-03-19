#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GPS signal health
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------
    /// SvId   int  Satellite's SV ID 1..32
    /// Health int  Signal health 0..31
    ///

    class SetGpsSignalHealthForSV;
    typedef std::shared_ptr<SetGpsSignalHealthForSV> SetGpsSignalHealthForSVPtr;
    
    
    class SetGpsSignalHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsSignalHealthForSV();

      SetGpsSignalHealthForSV(int svId, int health);
  
      static SetGpsSignalHealthForSVPtr create(int svId, int health);
      static SetGpsSignalHealthForSVPtr dynamicCast(CommandBasePtr ptr);
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

