#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GPS nav data health
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------
    /// SvId   int  Satellite's SV ID 1..32
    /// Health int  Data health 0..7
    ///

    class SetGpsDataHealthForSV;
    typedef std::shared_ptr<SetGpsDataHealthForSV> SetGpsDataHealthForSVPtr;
    
    
    class SetGpsDataHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsDataHealthForSV();

      SetGpsDataHealthForSV(int svId, int health);
  
      static SetGpsDataHealthForSVPtr create(int svId, int health);
      static SetGpsDataHealthForSVPtr dynamicCast(CommandBasePtr ptr);
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

