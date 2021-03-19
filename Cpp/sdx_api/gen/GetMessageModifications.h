#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetMessageModifications is deprecated since 21.3. You may use GetAllMessageModificationIdsForSignal.
    /// 
    /// Get all event's IDs whose will modify the signal's message for this SV ID
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------
    /// Signal string Signal
    /// SvId   int    Satellite SV ID
    ///

    class GetMessageModifications;
    typedef std::shared_ptr<GetMessageModifications> GetMessageModificationsPtr;
    
    
    class GetMessageModifications : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMessageModifications();

      GetMessageModifications(const std::string& signal, int svId);
  
      static GetMessageModificationsPtr create(const std::string& signal, int svId);
      static GetMessageModificationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

