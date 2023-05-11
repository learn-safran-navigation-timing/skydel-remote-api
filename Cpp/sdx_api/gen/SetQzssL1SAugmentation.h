#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set Add an augmentation to the L1S navigation messages.
    ///
    /// Name       Type   Description
    /// ---------- ------ ----------------------------------------------------------------------------------
    /// System     string "GPS", "GLONASS", "Galileo", "BeiDou" or "QZSS"
    /// Prn        int    Satellite PRN number.
    /// AugmentIOD bool   Include the satellite Issue Of Data in L1S message.
    /// AugmentPRC bool   Include the satellite Pseudorange Correction in L1S message.
    /// Prc        double Pseudorange Correction to include in L1S message. Only used if AugmentPSR is True.
    /// Id         string Unique identifier of the augmentation.
    ///

    class SetQzssL1SAugmentation;
    typedef std::shared_ptr<SetQzssL1SAugmentation> SetQzssL1SAugmentationPtr;
    
    
    class SetQzssL1SAugmentation : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetQzssL1SAugmentation();

      SetQzssL1SAugmentation(const std::string& system, int prn, bool augmentIOD, bool augmentPRC, double prc, const std::string& id);

      static SetQzssL1SAugmentationPtr create(const std::string& system, int prn, bool augmentIOD, bool augmentPRC, double prc, const std::string& id);
      static SetQzssL1SAugmentationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** augmentIOD ****
      bool augmentIOD() const;
      void setAugmentIOD(bool augmentIOD);


      // **** augmentPRC ****
      bool augmentPRC() const;
      void setAugmentPRC(bool augmentPRC);


      // **** prc ****
      double prc() const;
      void setPrc(double prc);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

