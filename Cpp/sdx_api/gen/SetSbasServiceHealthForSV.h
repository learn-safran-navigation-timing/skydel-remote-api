#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Apply service provider for a satellite
    ///
    /// Name   Type Description
    /// ------ ---- ---------------------
    /// SvId   int  The satellite's SV ID
    /// Health int  The service provider
    ///

    class SetSbasServiceHealthForSV;
    typedef std::shared_ptr<SetSbasServiceHealthForSV> SetSbasServiceHealthForSVPtr;
    
    
    class SetSbasServiceHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSbasServiceHealthForSV();

      SetSbasServiceHealthForSV(int svId, int health);

      static SetSbasServiceHealthForSVPtr create(int svId, int health);
      static SetSbasServiceHealthForSVPtr dynamicCast(CommandBasePtr ptr);
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

