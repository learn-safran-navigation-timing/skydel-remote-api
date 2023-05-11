#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get active data set.
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------
    /// System string "GPS", "Galileo", "BeiDou", "NavIC" or "QZSS"
    ///

    class GetActiveDataSet;
    typedef std::shared_ptr<GetActiveDataSet> GetActiveDataSetPtr;
    
    
    class GetActiveDataSet : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetActiveDataSet();

      GetActiveDataSet(const std::string& system);

      static GetActiveDataSetPtr create(const std::string& system);
      static GetActiveDataSetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

