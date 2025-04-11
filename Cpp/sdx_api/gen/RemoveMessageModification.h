#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command RemoveMessageModification is deprecated since 21.3. You may use RemoveMessageModificationForSignal.
    /// 
    /// Removes the signal for the message modification.
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------------------------------------------------------------------
    /// Signal string Signal key, accepted values : "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
    ///                                             "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B2a", "B1C", "B3I",
    ///                                             "QZSSL1CA", "QZSSL1CB", "QZSSL1S", "NAVICL5", "NAVICS", "SBASL1", "SBASL5",
    ///                                             "PULSARXL", "PULSARX1" and "PULSARX5"
    /// Id     string Unique identifier
    ///

    class RemoveMessageModification;
    typedef std::shared_ptr<RemoveMessageModification> RemoveMessageModificationPtr;
    
    
    class RemoveMessageModification : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RemoveMessageModification();

      RemoveMessageModification(const std::string& signal, const std::string& id);

      static RemoveMessageModificationPtr create(const std::string& signal, const std::string& id);
      static RemoveMessageModificationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

